using SpellingCheckerApp;

var path = @"C:\Users\Gygabyte\source\repos\Studies\5 sem\SP\repos\SP-2023\trunk\PO210640\task_03\Lab_03_Console\Lab_03_Console\Source\5000-words.txt";

var reader = new StreamReader(path);

var vocabulary = new List<string>(reader.ReadToEnd().Split().Select(str => str.Trim()));

var checker = new SpellingChecker(vocabulary);
var text = "Timr to veat yoyr axs";
var result = checker.CheckText(text);

Console.WriteLine(text);
Console.WriteLine(result);