using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InsertionSort
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] array3 = { 12, 15, 25, 11, 1344, 14, 13, 9, 2 };
            InsertionSort(ref array3);
            array3.ToList().ForEach(i => Console.Write(i.ToString() + " "));
        }

        static void InsertionSort(ref int[] nums)
        {
            int position = 0, temp_value;
            for(int i=0; i<nums.Length; i++)
            {
                // Position wird initialisiert
                position = i;
                // Der Wert aus i wird aus dem Array genommen.
                temp_value = nums[i];

                //Schiebt das Array gegen null
                while ((position > 0))
                {
                    // Abbruchbedingung wenn der entnommene Wert kleiner
                    // oder gleich dem ausgewählten Wert entspricht
                    if (nums[position - 1] <= temp_value)
                    {
                        break;
                    }
                    nums[position] = nums[position - 1];
                    //Schieben
                    position--;
                }
                // Setzt den entnommenen Wert an die Stelle
                nums[position] = temp_value;
            }
        }
    }
}
