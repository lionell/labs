var Pwn = artifacts.require("./Pwn.sol");
module.exports = function(deployer) {
  deployer.deploy(Pwn);
};
