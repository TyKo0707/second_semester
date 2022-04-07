import pickle


class Call:
    def __init__(self, tel_number, start_time, end_time, price):
        self.tel_number = tel_number
        self.start_time = start_time
        self.end_time = end_time
        self.price = price


def show_res():
    print('{:15}\t{:12}\t{:10}\t{:10}\t'.format('Phone number:', 'Call start:', 'Call end:', 'Price for call:'))
    with open('calls.txt', 'rb') as file:
        bin_data = file.read()
        clients = pickle.loads(bin_data)['calls']
        for client in clients:
            print('{:15}\t{:12}\t{:10}\t{:<10}\t'
                  .format(f'0{client.tel_number}', client.start_time, client.end_time, client.price))


def price_for_call(start, end, price_day, price_night):
    buff = [start.split(':'), end.split(':')]
    start_min = int(buff[0][0]) * 60 + int(buff[0][1])
    end_min = int(buff[1][0]) * 60 + int(buff[1][1])
    diff = end_min - start_min
    if 9 < int(buff[0][0]) < 20:
        return diff * price_day
    else:
        return diff * price_night


def delete_cols():
    with open('calls.txt', 'rb') as file:
        bin_data = file.read()
        calls = pickle.loads(bin_data)['calls']
        buff = calls[::]
        for i in range(len(calls)):
            temp = [calls[i].start_time.split(':'), calls[i].end_time.split(':')]
            start_min = int(temp[0][0]) * 60 + int(temp[0][1])
            end_min = int(temp[1][0]) * 60 + int(temp[1][1])
            diff = end_min - start_min
            if diff <= 3:
                buff.pop(i)

    with open('calls.txt', 'wb') as file:
        pickle.dump({'calls': buff}, file)


def create_list():
    calls = []
    with open('calls.txt', 'wb') as file:
        buf = 'y'
        count = 1
        while buf == 'y':
            is_ok = True
            print(f'Client {count}')
            print('Telephone number: +380', end='')
            tel_number = input()
            print('Start time (HH:MM): ', end='')
            start_time = input()
            print('End time (HH:MM): ', end='')
            end_time = input()
            price = price_for_call(start_time, end_time, 1.5, 0.9)
            c = Call(tel_number, start_time, end_time, price)
            if price <= 0:
                is_ok = False
                print('Mismatch in time')
            if is_ok:
                calls.append(c)
            print('Add another client? (y/n)')
            buf = input()
            count += 1
        pickle.dump({'calls': calls}, file)


if __name__ == '__main__':
    create_list()
    print('Data before deleting:')
    show_res()
    print('\nData after deleting:')
    delete_cols()
    show_res()
