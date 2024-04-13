extern "C" __declspec(dllexport) bool elementExist(int* array, int temp, int i)
{
    //Проверяем условие чтобы не выйти за границы массива
    if (i < temp) return false;

    //Нахождение нужного элемента (возврат при успешом завершении)
    if (array[i] <= i * i) return true;

    //Проверяем предыдущий элемент (при false-проверяем предыдущий)
    else return elementExist(array, temp, i - 1);
}