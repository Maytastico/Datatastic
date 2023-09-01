using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SelectionSort
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] array1 = { 5, 2, 9, 7, 3 };
            array1.ToList().ForEach(i => Console.Write(i.ToString()));
            Console.WriteLine("");
            SelectionSort(ref array1);
            array1.ToList().ForEach(i => Console.Write(i.ToString()));
            Console.WriteLine("");

            int[] array3 = new int[]
            {
                26, 48, 73, 12, 55, 85, 99, 63, 75, 4,
                19, 88, 88, 62, 12, 27, 95, 90, 96, 75,
                57, 17, 39, 74, 41, 51, 8, 63, 23, 72,
                60, 86, 12, 50
            };
            array3.ToList().ForEach(i => Console.Write(i.ToString()));
            Console.WriteLine("");
            SelectionSort(ref array3);
            array3.ToList().ForEach(i => Console.Write(i.ToString()));
            Console.WriteLine("");
            Console.ReadLine();
        }

        static void SelectionSort(ref int[] nums)
        {
            int lowestNumber = 0;
            for(int i=0;i<nums.Length;i++)
            {
                lowestNumber = i;
                for(int j=i+1;j<nums.Length;j++)
                {
                    if (nums[j] < nums[lowestNumber])
                    {
                        lowestNumber = j;
                    }
                }

                if(lowestNumber != i) { 
                    //Swap
                    int temp = nums[i];
                    nums[i] = nums[lowestNumber];
                    nums[lowestNumber] = temp;
                }

            }
        }
    }
}
