// Lab3.Var3(4,8).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
//Класс матрицы 3x3


class matrix //Класс "Матрица 3х3"
{
private:
	double  i00, i01, i02,
		i10, i11, i12,
		i20, i21, i22;
public:
	matrix( )
	{


	};
	matrix(double p00, double p01, double p02, double p10, double p11, double p12, double p20, double p21, double p22)
	{
		 i00 = p00;
		 i01 = p01;
		 i02 = p02;
		 i10 = p10;
		 i11 = p11;
		 i12 = p12;
		 i20 = p20;
		 i21 = p21;
		 i22 = p22;

	};
	matrix(double k1)
	{
		i00 = k1;
		i01 = k1;
		i02 = k1;
		i10 = k1;
		i11 = k1;
		i12 = k1;
		i20 = k1;
		i21 = k1;
		i22 = k1;

	}

	matrix(const matrix& c)
	{
		i00 = c.i00; i01 = c.i01; i02 = c.i02;
		i10 = c.i10; i11 = c.i11; i12 = c.i12;
		i20 = c.i20; i21 = c.i21; i22 = c.i22;
	}
	~matrix()
	{

	};
	
	// оператор присваивания 
	matrix operator =(const matrix& c)
	{
		i00 = c.i00; i01 = c.i01; i02 = c.i02;
		i10 = c.i10; i11 = c.i11; i12 = c.i12;
		i20 = c.i20; i21 = c.i21; i22 = c.i22;
		return (*this);
	};
	// оператор +=
	matrix& operator += (matrix& c)
	{
		i00 += c.i00; i01 += c.i01; i02 += c.i02;
		i10 += c.i10; i11 += c.i11; i12 += c.i12;
		i20 += c.i20; i21 += c.i21; i22 += c.i22;
		return *this;
	};

	// оператор сложения
	matrix operator + (const matrix& c) 
	{
		matrix b;
	    (b.i00 = i00 + c.i00, b.i01 = i01 + c.i01, b.i02 = i02 + c.i02,
			b.i01 = i10 + c.i10, b.i11 = i11 + c.i11, b.i12 = i12 + c.i12,
			b.i20 = i20 + c.i20, b.i21 = i21 + c.i21, b.i22 = i22 + c.i22);
		 return b;
	}
	// оператор вычитания
	matrix operator - (const matrix& c)
	{
		matrix b;
		   (b.i00=i00 - c.i00, b.i01=i01 - c.i01, b.i02 = i02 - c.i02,
			 b.i10=  i10 - c.i10,b.i11= i11 - c.i11, b.i12= i12 - c.i12,
			b.i20 =i20 - c.i20, b.i21= i21 - c.i21, b.i22 = i22 - c.i22);
		 return b;
	}
	
	//Сравнение матриц 
	 // оператор <.
	matrix operator <(const matrix& c)
	{
		matrix b;
		if (((1 * b.i00 * ((b.i11 * b.i22) - (b.i21 * b.i12))) + (-1 * b.i01 * ((b.i10 * b.i22) - (b.i20 * b.i12))) + (b.i02 * ((b.i10 * b.i21) - (b.i20 * b.i11)))) < ((1 * c.i00 * ((c.i11 * c.i22) - (c.i21 * c.i12))) + (-1 * c.i01 * ((c.i10 * c.i22) - (c.i20 * c.i12))) + (c.i02 * ((c.i10 * c.i21) - (c.i20 * c.i11)))))
			return b;
	 }

	 
	 // оператор >.
	matrix operator >(const matrix& c)
	{
		matrix b;
		if (((1 * b.i00 * ((b.i11 * b.i22) - (b.i21 * b.i12))) + (-1 * b.i01 * ((b.i10 * b.i22) - (b.i20 * b.i12))) + (b.i02 * ((b.i10 * b.i21) - (b.i20 * b.i11)))) > ((1 * c.i00 * ((c.i11 * c.i22) - (c.i21 * c.i12))) + (-1 * c.i01 * ((c.i10 * c.i22) - (c.i20 * c.i12))) + (c.i02 * ((c.i10 * c.i21) - (c.i20 * c.i11)))))
			return b;
	}
	 // оператор ==.
	matrix operator ==(const matrix& c)
	{
		matrix b;
		if (((1 * b.i00 * ((b.i11 * b.i22) - (b.i21 * b.i12))) + (-1 * b.i01 * ((b.i10 * b.i22) - (b.i20 * b.i12))) + (b.i02 * ((b.i10 * b.i21) - (b.i20 * b.i11)))) == ((1 * c.i00 * ((c.i11 * c.i22) - (c.i21 * c.i12))) + (-1 * c.i01 * ((c.i10 * c.i22) - (c.i20 * c.i12))) + (c.i02 * ((c.i10 * c.i21) - (c.i20 * c.i11)))))
			return b;
	}

	// оператор умножения
	matrix operator * (const matrix& c)
	{
		matrix b;
		         (b.i00 = i00 * c.i00 + i01 * c.i10 + i02 * c.i20,
			      b.i01 = i00 * c.i01 + i01 * c.i11 + i02 * c.i21,
			      b.i02 = i00 * c.i02 + i01 * c.i12 + i02 * c.i22,
			      b.i10 = i10 * c.i00 + i11 * c.i10 + i12 * c.i20,
			      b.i11 = i10 * c.i01 + i11 * c.i11 + i12 * c.i21,
			      b.i12 = i10 * c.i02 + i11 * c.i12 + i12 * c.i22,
			      b.i20 = i20 * c.i21 + i01 * c.i22 + i02 * c.i20,
			      b.i21 = i20 * c.i21 + i01 * c.i22 + i02 * c.i21,
			      b.i22 = i20 * c.i21 + i01 * c.i22 + i02 * c.i22);
		 return b;
	}
	friend std::ostream& operator<< (std::ostream&, const matrix&);
	friend std::istream& operator>> (std::istream&, matrix&);
	
};
// перегрузка оператора << для матрицы
std::ostream& operator<< (std::ostream& out, const matrix& c)
{
	out  << c.i00 << "  " << c.i01 << "  " << c.i02 << " " << std::endl;
	out  << c.i10 << "  " << c.i11 << "  " << c.i12 << " " << std::endl;
	out  << c.i20 << "  " << c.i21 << "  " << c.i22 << " " << std::endl;
	return out;
}

// перегрузка оператора >> для матрицы
std::istream& operator>> (std::istream& in, matrix& c)
{
	in >> c.i00 >> c.i01 >> c.i02 >> c.i10 >> c.i11 >> c.i12 >> c.i20 >> c.i21 >> c.i22 ;
	return in;
}
//Класс треугольника на плоскости 
struct vector
{
	double x;
	double y;
};
class delta //класс треугольник.
{
private:
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int t1t2 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	int t1t3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	int t2t3 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	int perimetr = t1t2 + t1t3 + t2t3;
	int S = sqrt(perimetr * (perimetr - t1t2) * (perimetr - t1t3) * (perimetr - t2t3));
	;
public:
	//Конструктор по умолчанию 
	delta()
	{

	};
	//Констркутор копирования 
	delta(int a1, int a2, int a3, int b1, int b2, int b3, int perimetr1, int S1, int t1t2b, int t1t3b, int t2t3b)
	{
		x1 = a1;
		x2 = a2;
		x3 = a3;
		y1 = b1;
		y2 = b2;
		y3 = b3;
		perimetr = perimetr1;
		S = S1;
		t1t2 = t1t2b;
		t1t3 = t1t3b;
		t2t3 = t2t3b;
	};
	delta(int tochka)
	{
		x1 = tochka;
		x2 = tochka;
		x3 = tochka;
		y1 = tochka;
		y2 = tochka;
		y3 = tochka;
		perimetr = 0;
		S = 0;
		t1t2 = 0;
		t1t3 = 0;
		t2t3 = 0;
	}
	;
	delta(const delta& c)
	{
		x1 = c.x1;
		x2 = c.x2;
		x3 = c.x3;
		y1 = c.y1;
		y2 = c.y2;
		y3 = c.y3;
		t1t2 = c.t1t2;
		t1t3 = c.t1t3;
		t2t3 = c.t2t3;
		perimetr = c.perimetr;
		S = c.S;
	};
	//Дестркутор 
	~delta()
	{

	};
	//Сравнение  площадей 
	delta& operator ==(const delta& c) //оператор ==.
	{
	
		if (S == c.S)
			return *this;
	};
	delta& operator	!=(const delta& c) // оператор !=.
	{
		
		if (S != c.S)
			return *this;
	}
	delta& operator >(const delta& c) //оператор >.
	{
		if (S > c.S)
			return *this;
	};
	delta& operator	<(const delta& c) // оператор <.
	{
		
		if (S < c.S)
			return *this;
	}
	
	delta& operator +=(const vector& c)
	{
		x1 += c.x;
		x2 += c.x;
		x3 += c.x;
		y1 += c.y;
		y2 += c.y;
		y3 += c.y;
		return *this;
	};
	friend std::ostream& operator<< (std::ostream&, const delta&);
	friend std::istream& operator>> (std::istream&, delta&);

}; 
// перегрузка оператора << для треугольника 
std::ostream& operator<< (std::ostream& out, const delta& c)
{
	out << "Tocka 1=(" << c.x1 << " ; " << c.y1 << ")" << std::endl;
	out << "Tocka 2=(" << c.x2 << " ; " << c.y2 << ")" << std::endl;
	out << "Tocka 3=(" << c.x3 << " ; " << c.y3 << ")" << std::endl;
	return out;
}

// перегрузка оператора >> для треугольника
std::istream& operator>> (std::istream& in, delta& c)
{
	in >> c.x1 >> c.y1 >> c.x2 >> c.y2 >> c.x3 >> c.y3;
	return in;
}
int main()
{
	delta a;
	vector b{ 1,4 };
	std::cin >> a;
	a += b;
	std::cout << a ;
}

