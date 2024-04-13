namespace Laborotory7
{
    class Program 
    { 
        public static void Main()
        {
            Triangle triangle = new Triangle(4,5,6);
            triangle.Print();// Выводим информацию о начальном треугольнике со стороной 4

            triangle++;// Увеличиваем длину каждой стороны треугольника
            triangle.Print();// Выводим новую информацию о "новом" треугольнике

            triangle -= 5;// Уменьшаем длину каждой стороны треугольника (однако сейчас =5)
            triangle.Print();// Выводим информацию о "третьем" треугольнике

            triangle -= 5;
            triangle /= 2;// Получаем длину стороны 2.5
            triangle.Print();// Вывели информацию о новом треугольнике со стороной 2.5

            // Проверяем на равностороннесть треугольник
            if (triangle)
            {
                Console.WriteLine("It's true!\n");
            }
            else
            {
                Console.WriteLine("It's false!");
            }

            double number = 5.5;// Объявляем "новое" число
            triangle = number; // Присваиваем сторону новому числу

            triangle.Print();

            number = (double)triangle;// Преобразуем "новое число" в сторону треугольника явно

            triangle.Print();// Выводим информацию после преобразования
        }
    }

}