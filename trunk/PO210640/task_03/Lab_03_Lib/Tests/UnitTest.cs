using SpellingCheckerApp;

namespace Tests;

[TestClass]
public class UnitTest
{
    private static SpellingChecker Checker { get; set; }

    [ClassInitialize]
    public static void ClassInitialize(TestContext testContext)
    {
        var path = @"C:\Users\Gygabyte\source\repos\Studies\5 sem\SP\repos\SP-2023\trunk\PO210640\task_03\Lab_03_Lib\Tests\Source\5000-words.txt";

        var reader = new StreamReader(path);

        var vocabulary = new List<string>(reader.ReadToEnd().Split().Select(str => str.Trim()));

        Checker = new SpellingChecker(vocabulary);
    }


    [TestMethod]
    [DataRow("word", "worf")]
    [DataRow("animal", "aninal")]
    [DataRow("free", "frer")]
    public void TestWord(string origin, string mistake)
    {
        Assert.AreEqual(origin, Checker.CheckWord(mistake));
    }

    [TestMethod]
    [DataRow("i like test", "i likd tesi")]
    public void TestText(string origin, string mistake)
    {
        Assert.AreEqual(origin, Checker.CheckText(mistake));
    }
}