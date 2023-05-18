def count_chars(string):
    char_count = {}
    for char in string:
        if char not in char_count:
            char_count[char] = 1
        else:
            char_count[char] += 1
    return char_count

# пример использования функции
string = "Hello, world!".lower()
char_count = count_chars(string)
for char, count in char_count.items():
    print(f"{char}: {count}")