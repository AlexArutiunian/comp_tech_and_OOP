


13. Функция get_really_any_hexadecimal() сначала считывает строку, используя std::getline(). Затем она проходит по каждому символу в строке и проверяет, является ли он шестнадцатеричной цифрой (0-9, A-F, a-f), используя isxdigit(). Если символ является шестнадцатеричной цифрой, то он преобразуется в верхний регистр с помощью toupper() и добавляется к числу, которое затем возвращается. Если символ не является шестнадцатеричной цифрой, он игнорируется. Концом ввода считаются пробел и символ новой строки, так что функция прекращает чтение, как только встречает любой из этих символов.