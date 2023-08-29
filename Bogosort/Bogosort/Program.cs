using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bogosort
{
    public class Program
    {
        static void Main(string[] args)
        {

            int[] sorted = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int[] unsorted = { 12, 15, 11, 14, 13 };

            Console.WriteLine(IsSorted(sorted));
            unsorted.ToList().ForEach(i => Console.Write(i.ToString()));
            Console.WriteLine("");
            MonkeySort(ref unsorted);
            unsorted.ToList().ForEach(i => Console.Write(i.ToString()));
        }

        public static void MonkeySort(ref int[] nums)
        {
            Random rnd = new Random();

            while (!IsSorted(nums))
            {
                int a_random = rnd.Next(nums.Length);
                int b_random = rnd.Next(nums.Length);

                int temp = nums[a_random];
                nums[a_random] = nums[b_random];
                nums[b_random] = temp;
            }
        }

        public static Boolean IsSorted(int[] nums)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                if (i == nums.Length-1) break;
                if (nums[i] > nums[i + 1]) return false;
            }
            return true;
        }
    }
}
