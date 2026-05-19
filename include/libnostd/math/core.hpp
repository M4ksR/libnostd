#ifndef LIBNOSTD_MATH_CORE_HPP
#define LIBNOSTD_MATH_CORE_HPP

/**
 * @brief Basic mathematical utils
 * @todo  Сделать полное покрытие тестами функций из math/core.hpp
 */
namespace math {
	/**
	 * @brief 		Вычисление квадрата числа
	 * @details 	Вычисление квадрата через умножение числа на самого себя
	 * 				(number * number)
	 * @param[in]	num	Вещественное число
	 * @return		Квадрат числа
     */
	double square(double num);

    /**
     * @brief       Быстрое (бинарное) возведение в целую степень
     * @details     Возведение числа в целую степень с абсолютной точностью.
	 *				Алгоритм: возводим число в степени 1, 2, 4, ..., 2n,
	 *				каждый раз, пока степень не равна 0, сдвигая на 1 бит вправо.
	 *				Если последний бит 1 (не равен 0), домножаем результат на base.
     * @param[in]   base Основание. Вещественное число
	 * @param[in]	exp Экспонента. Неотрицательное длинное целое
     * @return      Число, возведенное в степень \f$ {base}^{exp} \f$.
     */
	double fast_power(double base, unsigned long long exp);

    /**
     * @brief       Вычисление корня из вещественного числа по формуле Герона
     * @details     Метод эквивалентен использованию метода Ньютона для решения
	 *				уравнения \f$ x^2 - S = 0 \f$.
	 * 				Алгоритм можно представить следующим образом:
	 *				\f$ x_{0}\approx {\sqrt {S}}, \f$
	 *			    \f$ x_{n+1}={\frac {1}{2}}\left(x_{n}+{\frac {S}{x_{n}}}\right), \f$
	 *				\f$ {\sqrt {S}}=\lim _{n\to \infty }x_{n}. \f$
     * @param[in]   num Положительное вещественное число.
     * @return      Квадратный корень из числа
     */
	double sqrt_heron(double num);

    /**
     * @brief       Факториал по модулю (n! mod m)
     * @details     Вычисление
     *              \f$ (1 \cdot 2 \cdot ... \cdot n) \mod m \f$.
     * @param[in]   n Положительное целое число.
	 * @param[in]   m Положительное натуральное.
     * @return      Факториал n по модулю m
     */
	unsigned long factorial(unsigned long n, unsigned long m);

    /**
     * @brief       Прозведение чисел из диапазона по модулю
     * @details     Для заданных чисел a и b (a<b) вычисление
     *              \f$ (a \cdot (a+1) \cdot ... \cdot (b-1) \cdot b) \mod m \f$.
     * @param[in]   a Положительное целое число. Левая граница диапазона.
     * @param[in]   b Положительное целое число. Правая граница диапазона.
     * @param[in]   m Положительное натуральное. Модуль.
     * @return      Произведение чисел из диапазона по модулю.
     */
    unsigned long prod(unsigned long a, unsigned long b, unsigned long m);


    /**
     * @brief       Бинарное возведение в степень
     * @param[in]   Положительное целое число. Основание.
     * @param[in]   Положительное целое число. Степень.
     * @param[in]   Положительное целое число. Модуль.
     * @return      \f$ (a^{deg}) \mod m \f$
     */
    unsigned long binpowmod(unsigned long a, unsigned long deg, unsigned long m);

    /**
     * @brief     Обратный по модулю
     * @param[in] Положительное натуральное число.
     * @param[in] Положительное простое число. Модуль.
	 * @warning   Числа должны быть взаимнопростые.
     * @return    обратный элемент по модулю
     */
    unsigned long invmod(unsigned long a, unsigned long m);

    /**
     * @brief	   Расширенный алгоритм Евклида
     * @details    \f$ a \cdot x + b \cdot y = gcd(a, b) \f$
     *
     * @param[in]  Положительное натуральное число a
     * @param[in]  Положительное натуральное число b
     * @param[out] Ссылка на беззнаковое целое x
     * @param[out] Ссылка на беззнаковое целое y
     * @return     Наибольший общий делитель a и b
     */
    unsigned long gcdex(unsigned long a, unsigned long b, unsigned long &x, unsigned long &y);

}

#endif

