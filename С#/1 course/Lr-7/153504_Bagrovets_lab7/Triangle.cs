using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotory7
{
    internal class Triangle
    {

        private double _firstSide = 10, _secondSide = 10, _thirdSide = 10;

        public double FirstSide { get { return _firstSide; } set { _firstSide = value; } }

        public double SecondSide { get { return _secondSide; } set { _secondSide = value; } }

        public double ThirdSide { get { return _thirdSide; } set { _thirdSide = value; } }

        public double Perimetr {get { return _firstSide + _secondSide + _thirdSide; } }

        public double Square 
        { 
            get 
            {
                return Math.Sqrt(Perimetr / 2 * (Perimetr / 2 - _firstSide) *
                    (Perimetr / 2 - _secondSide) * (Perimetr / 2 - _thirdSide));
            }
        }

        // Задаем параметры треугольника
        public Triangle(double a, double b, double c)
        {
            _firstSide = a;
            _secondSide = b;
            _thirdSide = c; 
        }

        // Перегружаем
        public Triangle(double a, double b):this(a,a,b)
        {
           
        }

        // Аналогично
        public Triangle(double a):this(a,a,a)
        {
           
        }

        // -//-
        public Triangle()
        {

        }

        // Перегружаем оператор + (создав новый треугольник(первый треугольник) )
        public static Triangle operator +(Triangle firstTriangle , double value)
        {
            firstTriangle.FirstSide += value;
            firstTriangle.SecondSide += value;
            firstTriangle.ThirdSide += value;

            return firstTriangle;
        }
        
        // Перегружаем оператор - 
        public static Triangle operator -(Triangle firstTriangle ,int value)
        {
            if (firstTriangle.FirstSide <= value || firstTriangle.SecondSide <= value || firstTriangle.ThirdSide <= value)
            {
                return firstTriangle;
            }

            firstTriangle.FirstSide -= value;
            firstTriangle.SecondSide -= value;
            firstTriangle.ThirdSide -= value;

            return firstTriangle;
        }

        // Перегружаем оператор *
        public static Triangle operator *(Triangle firstTriangle , double value)
        {
            firstTriangle.FirstSide *= value;
            firstTriangle.SecondSide *= value;
            firstTriangle.ThirdSide *= value;

            return firstTriangle;
        }
        
        // Перегружаем оператор /
        public static Triangle operator /(Triangle firstTriangle , double value)
        {
            firstTriangle.FirstSide /= value;
            firstTriangle.SecondSide /= value;
            firstTriangle.ThirdSide /= value;

            return firstTriangle;
        }

        // Перегружаем оператор ++
        public static Triangle operator ++(Triangle firstTriangle)
        {
            firstTriangle.FirstSide++;
            firstTriangle.SecondSide++;
            firstTriangle.ThirdSide++;

            return firstTriangle;
        }    
        
        // Перегружаем оператор --
        public static Triangle operator --(Triangle firstTriangle)
        {
            if (firstTriangle.FirstSide < 2 || firstTriangle.SecondSide < 2 || firstTriangle.ThirdSide < 2)
            {
                return firstTriangle;
            }

            firstTriangle.FirstSide--;
            firstTriangle.SecondSide--;
            firstTriangle.ThirdSide--;

            return firstTriangle;
        }

        public static bool operator >(Triangle firstTriangle, Triangle secondTriangle)
        {
            return firstTriangle.Square > secondTriangle.Square;
        }

        public static bool operator <(Triangle firstTriangle, Triangle secondTriangle)
        {
            return firstTriangle.Square < secondTriangle.Square;
        }

        public static bool operator >=(Triangle firstTriangle, Triangle secondTriangle)
        {
            return firstTriangle.Square >= secondTriangle.Square;
        }

        public static bool operator <=(Triangle firstTriangle, Triangle secondTriangle)
        {
            return firstTriangle.Square <= secondTriangle.Square;
        }

        //перегружаем true/false по отдельности - но можно перегрузить сразу два
        public static bool operator true(Triangle triangle)
        {
            return triangle.FirstSide == triangle.SecondSide && triangle.ThirdSide == triangle.FirstSide;
        }

        public static bool operator false(Triangle triangle)
        {
            return triangle.FirstSide != triangle.SecondSide && triangle.ThirdSide != triangle.FirstSide;
        }


        // Явно преобразуем
        public static implicit operator Triangle(double a)
        {
            return new Triangle(a);
        }

        // Неявно преобразуем
        public static explicit operator double(Triangle triangle)
        {
            return triangle.FirstSide;
        }


        public void Print()
        {
            Console.WriteLine($"First side - {_firstSide}\nSecond side - {_secondSide}\nThird side -{_thirdSide}");
            Console.WriteLine($"Square - {Square}\nPerimetr - {Perimetr}\n");
        }
    }
}
