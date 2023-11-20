
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{


    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        //Radix sort will take O(nm) time
        //Create a hashmap that maps anagram stat buckets -> hash value. Calculate hash for all words will take O(nm) time
        //Worst case O(n^2m), best case O(nm)

        const int MOD_FACTOR = 65003;
        List<int[]> anagramStat = new List<int[]>();
        List<IList<string>> answer = new List<IList<string>>();
        List<int>[] hashMap = new List<int>[MOD_FACTOR];
        int groups = 0;

        //Start
        int sL = strs.Length;
        for (int i = 0; i < sL; i++)
        {
            //Count occurrences
            int[] radix = new int[26];
            for (int j = 0; j < strs[i].Length; j++)
            {
                radix[strs[i][j] - 'a'] += 1;
            }

            //Calculate hashes
            int hashValue = 0;
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < radix[j]; k++)
                {
                    hashValue = hashValue * 31 + (j + 1);
                    hashValue %= MOD_FACTOR;
                }
            }
            if (hashMap[hashValue] == null)
            {
                hashMap[hashValue] = new List<int>();
            }

            //Find in hash map
            int aId = -1;
            for (int j = 0; j < hashMap[hashValue].Count; j++)
            {
                bool flag = true;
                int tId = hashMap[hashValue][j];
                for (int k = 0; k < 26; k++)
                {
                    if (anagramStat[tId][k] != radix[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    aId = tId;
                    break;
                }
            }

            // If found
            if (aId != -1)
            {
                answer[aId].Add(strs[i]);
            }
            else
            {
                anagramStat.Add(radix);
                answer.Add(new List<string>());
                answer[groups].Add(strs[i]);
                hashMap[hashValue].Add(groups);
                groups++;
            }

        }
        for (int i = 0; i < answer.Count; i++)
        {
            Console.WriteLine("===================");
            for (int j = 0; j < answer[i].Count; j++)
            {
                Console.Write(answer[i][j] + ",");
            }
            Console.Write("\n");
        }
        return answer;


    }

    public static int Main()
    {
        Solution s = new Solution();
        s.GroupAnagrams(["a"]);
        return 0;
    }
}
