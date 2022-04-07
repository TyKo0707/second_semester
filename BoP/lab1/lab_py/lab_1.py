import re


def input_text():
    text = []
    print("Enter your text: (press CTRL + X or empty line to stop)")
    flag = True
    exit_line = "\u0018"
    while flag:
        line = str(input())
        if (line == exit_line) or (line == ""):
            flag = False
        else:
            text.append(line)
    return text


def create_file(file_name: str, text=None, enc='utf-8'):
    flag = True
    while flag:
        choice = input("You want to add text or rewrite file? "
                       "(Enter 'a' if you want to add text; 'r' if you want to rewrite text): ")
        if choice == 'a':
            new_file = open(file_name, 'a', encoding=enc)
            new_file.write('\n' + text[0])
            flag = False
        if choice == 'r':
            new_file = open(file_name, 'w', encoding=enc)
            new_file.write(text[0])
            flag = False
        else:
            print('Wrong symbol. Try again')

    for i in range(1, len(text)):
        new_file.write('\n' + text[i])

    new_file.close()


def find_min_word(text):
    min_words = []
    for i in range(len(text)):
        buff = re.findall(r"[\w']+", text[i])
        min_words.append(min((word for word in buff if word), key=len))

    return min_words


def print_file(file):
    lines = (open(file, 'r').readlines())
    for string in lines:
        print(string)


if __name__ == '__main__':
    print('Creating first file: ')
    text = input_text()
    create_file('first_file.txt', text)
    print_file('first_file.txt')
    shortest_words = find_min_word(text)

    print('\nCreating second file: ')
    lines = []
    for i in range(len(text)):
        lines.append(text[i] + f' - ({len(shortest_words[i])} {shortest_words[i]})')
    create_file('second_file.txt', lines)
    print_file('second_file.txt')


