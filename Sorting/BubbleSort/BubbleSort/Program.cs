using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BubbleSort
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] unsorted = { 28337, 12377, 10614, 2755, 52611, 63142, 63652, 25211, 44769, 17324 };
            unsorted.ToList().ForEach(i => Console.Write($"{i.ToString()} "));
            Console.WriteLine("");
            BubbleSort(ref unsorted);
            unsorted.ToList().ForEach(i => Console.Write($"{i.ToString()} "));
            Console.WriteLine("");
        }

        static void BubbleSort(ref int[] nums)
        {
            int upperIndex = nums.Length - 1;
            bool sorted = false;
            while(!sorted)
            {
                sorted = true;
                for (int i = 0; i < upperIndex; i++)
                {
                    Console.Write(i + " : ");
                    nums.ToList().ForEach(y => Console.Write($"{y.ToString()} ")); Console.WriteLine("");
                    if (nums[i] > nums[i + 1])
                    {
                        int temp = nums[i];
                        nums[i] = nums[i + 1];
                        nums[i + 1] = temp;
                        sorted = false;
                    }
                }
                Console.WriteLine("");
                upperIndex--;
            }
        }
    }
}
