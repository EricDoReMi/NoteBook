using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using InterfaceExample05;

namespace UnitTestInterfaceExample05
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void PowerLowerThanZero_OK()
        {
            var fan = new DeskFan(new PowerSupplyLowerThanZero());
            var actual=fan.Work();
            var expected = "Won't work";
            Assert.AreEqual(expected,actual);
        }
    }

    class PowerSupplyLowerThanZero : IpowerSupply {
        public int GetPower() {
            return 0;
        }
    }
}
