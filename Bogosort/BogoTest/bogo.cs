using Bogosort;
namespace BogoTest
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestUnsorted()
        {
            int[] array1 = { 5, 2, 9, 7, 3 };
            int[] array2 = { 8, 1, 6, 4, 10 };
            int[] array3 = { 12, 15, 11, 14, 13 };
            int[] array4 = { 20, 16, 18, 17, 19 };
            int[] array5 = { 23, 21, 22, 25, 24 };
            int[] array6 = { 30, 27, 28, 26, 29 };
            int[] array7 = { 35, 32, 31, 37, 33 };
            int[] array8 = { 40, 38, 34, 39, 36 };
            int[] array9 = { 46, 44, 42, 41, 43 };
            int[] array10 = { 49, 48, 50, 45, 47 };
            Assert.IsFalse(Bogosort.Program.IsSorted(array1));
            Assert.IsFalse(Bogosort.Program.IsSorted(array2));
            Assert.IsFalse(Bogosort.Program.IsSorted(array3));
            Assert.IsFalse(Bogosort.Program.IsSorted(array4));
            Assert.IsFalse(Bogosort.Program.IsSorted(array5));
            Assert.IsFalse(Bogosort.Program.IsSorted(array6));
            Assert.IsFalse(Bogosort.Program.IsSorted(array7));
            Assert.IsFalse(Bogosort.Program.IsSorted(array8));
            Assert.IsFalse(Bogosort.Program.IsSorted(array9));
            Assert.IsFalse(Bogosort.Program.IsSorted(array10));
        }

        [Test]
        public void TestMonkeyUnsortedArrays()
        {
            int[] array3 = { 3, 5, 1, 2, 6, 7, 4, 8, 9 };
            int[] array4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            Bogosort.Program.MonkeySort(ref array3);
            Array.Equals(array3, array4);

        }
        [Test]
        public void TestMonkeyUnsortedArrays2()
        {
            int[] array3 = { 12, 15, 11, 14, 13 };
            int[] array4 = { 11, 12, 13, 14, 15 };
            Bogosort.Program.MonkeySort(ref array3);
            Array.Equals(array3, array4);

        }
        [Test]
        public void TestMonkeyUnsortedArrays3()
        {
            int[] array3 = { 28337, 12377, 10614, 2755, 52611, 63142, 63652, 25211, 44769, 17324 };
            int[] array4 = { 2755, 10614, 12377, 17324, 25211, 28337, 44769, 52611, 63142, 63652 };
            Bogosort.Program.MonkeySort(ref array3);
            Array.Equals(array3, array4);

        }
        [Test]
        public void TestMonkeyUnsortedArrays4()
        {
            int[] array3 = new int[]
            {
                26, 48, 73, 12, 55, 85, 99, 63, 75, 4,
                19, 88, 88, 62, 12, 27, 95, 90, 96, 75
            };
            int[] array4 = new int[]
            {
                4, 12, 12, 19, 27, 48, 55, 62, 63, 73,
                75, 75, 85, 88, 88, 90, 95, 96, 99
            };
            Bogosort.Program.MonkeySort(ref array3);
            Array.Equals(array3, array4);

        }
    }
}