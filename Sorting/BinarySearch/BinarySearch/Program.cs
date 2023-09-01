using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearch
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] search = { 34, 36, 38, 39, 40 };
            Console.WriteLine(BinarySearchRecursiveInit(search, 36));
        }

        /// <summary>
        /// Takes a sorted array and looks for the number passed over toSearch
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="toSearch"></param>
        /// <returns></returns>
        public static int? BinarySearch(int[] nums, int toSearch) 
        {
            int low = 0, high = nums.Length-1, mid = 0;

            while (low <= high) {
                mid = (high + low) / 2;
                if (nums[mid] == toSearch)
                {
                    return mid;
                }
                else if (nums[mid] < toSearch)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
                
            }
            return null;
        }
        
        public static int? BinarySearchRecursiveInit(int[] nums, int toSearch) 
        {
            return BinarySearchRecursive(nums, toSearch, 0, nums.Length - 1);
        }

        public static int? BinarySearchRecursive(int[] nums, int toSearch, int low, int high)
        {
            int mid = (high + low) / 2;
            if (nums[mid] == toSearch)
            {
                return mid;
            }
            else if (nums[mid] < toSearch)
            {
                return BinarySearchRecursive(nums, toSearch, mid + 1, high);
            }
            else
            {
                return BinarySearchRecursive(nums, toSearch, mid, mid - 1);
            }
            return null;
        }



    }
}
