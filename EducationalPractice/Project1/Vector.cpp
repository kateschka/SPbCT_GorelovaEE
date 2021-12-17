template <typename T> class vector
{
private:
	T* _array; //указатель на массив
	int _arraySize; //размер массива

public:
	void push_back(T data)
	{
		T* _result = new T[++this->_arraySize]; //создаем новый массив размером исходного+1

		for (int index = 0; index < this->_arraySize; index++)
		{
			if (index != this->_arraySize - 1) //если не последний элемент массива
			{
				_result[index] = this->_array[index]; //переписываем знаение в новый массив
			}
			else
			{
				_result[index] = data; //записываем данные в последний элемент
				break;
			}
		}
		delete[] this->_array; //удаляем исходный массив
		this->_array = _result; //присваиваем ссылку на новый массив
	}

	void clear()
	{
		if (this->_array != nullptr)
		{
			::ZeroMemory(this->_array, this->_arraySize); //заполняет нулями блок памяти
		}
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}

	T operator [](int index) //получить значение по индексу
	{
		return this->_array[index];
	}

	int size() //получить размер вектора
	{
		return this->_arraySize;
	}

	vector() //конструктор по умолч
	{
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}
};