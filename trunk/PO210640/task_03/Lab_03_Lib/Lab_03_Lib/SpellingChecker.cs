using System.Text;

namespace SpellingCheckerApp;

public class SpellingChecker
{
    private List<string> Glossary { get; set; }
    private HashSet<string> HashGlossary { get; set; }
    private Dictionary<int, List<string>> Glossaries { get; set; }


    public SpellingChecker(List<string> glossary)
    {
        Glossary = new(glossary.Count);
        foreach (string str in glossary)
        {
            Glossary.Add(str.ToLower());
        }
        Glossary.Sort();

        HashGlossary = new(glossary);

        Glossaries = new();

        foreach (string word in Glossary)
        {
            int length = word.Length;
            if (Glossaries.ContainsKey(length)) Glossaries[length].Add(word);
            else
            {
                Glossaries.Add(length, new List<string>());
                Glossaries[length].Add(word);
            }
        }
    }

    public string CheckText(string text)
    {
        var span = new Span<char>(text.ToArray());

        var sb = new StringBuilder();

        int index = 0;
        while (index < span.Length)
        {
            var range = FindWord(span, index);
            if (range is (-1, -1))
            {
                sb.Append(span[index..]);
                break;
            }

            sb.Append(span[index..range.Item1]);

            var slice = span.Slice(range.Item1, range.Item2);
            var word = slice.ToString();
            var replacer = CheckWord(word);
            
            sb.Append(replacer);

            index = range.Item1 + range.Item2;
        } 

        return sb.ToString();
    }
    public string CheckWord(string word)
    {
        string lowWord = word.ToLower();

        if (HashGlossary.Contains(lowWord)) return word;

        int length = lowWord.Length;
        if (!Glossaries.ContainsKey(length)) return word;

        var list = Glossaries[length];

        int maxMatches = -1;
        double minDistance = double.MaxValue;
        string bestGuess = word;

        foreach (var item in list)
        {
            var matches = CountMathes(lowWord, item);
            if (matches < maxMatches) continue;

            if (matches > maxMatches)
            {
                bestGuess = item;
                maxMatches = matches;
                minDistance = CountDistance(lowWord, item);
                continue;
            }

            var distance = CountDistance(lowWord, item);
            if (distance < minDistance)
            {
                bestGuess = item;
                maxMatches = matches;
                minDistance = distance;
            }
        }

        return bestGuess;
    }

    private static int CountMathes(string word, string sample)
    {
        int mathes = 0;
        for (int i = 0; i < word.Length; i++)
        {
            if (word[i] == sample[i]) mathes++;
        }
        return mathes;
    }

    private static double CountDistance(string word, string sample)
    {
        int length = word.Length;
        byte[,] table = new byte[length + 1, length + 1];
        table.Initialize();

        byte max = 0;

        for (int i = 1; i < table.GetLength(0); i++)
        {
            for (int j = 1; j < table.GetLength(1); j++)
            {
                if (word[i - 1] == sample[j - 1])
                {
                    table[i, j] = (byte)(1 + table[i - 1, j - 1]);
                    if (table[i, j] > max) max = table[i, j];
                }
            }
        }

        return length - max;
    }









    private static (int, int) FindWord(ReadOnlySpan<char> text, int index)
    {
        int firstLetter = index;
        while (firstLetter < text.Length)
        {
            if (char.IsLetter(text[firstLetter])) break;
            firstLetter++;
        }

        if (firstLetter == text.Length) return (-1, -1);

        int length = 1;
        for (; firstLetter + length < text.Length; length++)
        {
            if (!char.IsLetter(text[firstLetter + length])) break;
        }

        return (firstLetter, length);
    }
}
