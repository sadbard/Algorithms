/*
В компании работает n разработчиков, где n — четное число. Сумасшедший менеджер решил разбить всех
разработчиков на команды по два человека.

Для этого он составил список всех разработчиков и назначил каждому из них номер по списку (от 1 до n)
и значение a[i] — уровень мастерства i-го в списке разработчика.

Очередную команду он составляет следующим образом:
1. первый разработчик в команде тот, кто идет первым в списке;
2. ему в пару подбирается такой, что разница их уровней минимальна (то есть минимально значение |ai−aj|,
где |x| — это модуль числа x); если таких кандидатов несколько, то выбирается из них тот, кто находится
раньше в списке;
3. эти два разработчика образуют команду и удаляются из списка.

Например, если массив a равен [2,1,3,1,1,4], то формирование команд будет происходить следующим образом:
1. назначим разработчикам номера [1,2,3,4,5,6] в соответствии с их положением в списке, первый среди них имеет
номер 1, его уровень мастерства a1=2, подходящими (с минимальной абсолютной разностью) являются
разработчики с номерами 2,3,4,5, первый среди них 2, таким образом первая команда — это разработчики
с номерами 1 и 2;
2. оставшиеся разработчики теперь имеют номера [3,4,5,6], первый среди них 3, его уровень a3=3, разработчик
с минимальной абсолютной разностью только один (номер 6), таким образом команда — разработчики с номерами 3 и 6;
3.оставшиеся разработчики имеют номера [4,5], первый среди них 4, его уровень a4=1, остался только разработчик
с номером 5, таким образом третья команда — разработчики с номерами 4 и 5.

    Ваша задача — помочь сумасшедшему менеджеру промоделировать процесс разбиения на команды. Обратите внимание,
что команды должны быть выведены в порядке, описанном выше в условии.
*/

#include <iostream>
#include <vector>

int main()
{
    int count = 0;

    std::cin >> count;
    const int MaxValue = 999;
    std::vector<std::vector<int>> table {};

    table.resize(count);

    for (int i = 0; i < count; ++i)
    {
        int cnt = 0;
        std::cin >> cnt;

        for (int j = 0; j< cnt; ++j)
        {
            int input = 0;
            std::cin >> input;
            table[i].push_back(input);
        }
    }

    for (auto &vec : table)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] == MaxValue)
                continue;

            int value = MaxValue;
            std::pair<int, int> save (0,0);

            for (int j = 0; j < vec.size(); ++j)
            {
                if (i == j || vec[j] == MaxValue)
                    continue;

                int tmp = abs(vec[i] - vec[j]);
                if (tmp < value)
                {
                    value = tmp;
                    save.first = i;
                    save.second = j;
                }
            }

            std::cout << save.first + 1 << ' ' << save.second + 1 << std::endl;
            vec[i] = vec[save.second] = MaxValue;
        }

        std::cout << std::endl;

    }

    return 0;
}
