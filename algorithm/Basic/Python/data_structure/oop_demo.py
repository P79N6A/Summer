class Oop(object):

    def __init__(self, name='default'):
        print('exec __init__!')
        self.name = name

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name


if __name__ == '__main__':
    obj_1 = Oop()
    obj_2 = Oop('sheng')

    print('obj_1 : ', obj_1.get_name())
    print('obj_2 : ', obj_2.get_name())

    print('Change Name!')
    obj_1.set_name('new_1')
    obj_2.set_name('new_2')

    print('obj_1 : ', obj_1.get_name())
    print('obj_2 : ', obj_2.get_name())

    obj_1.sex = 'man'
    print('obj_1 sex : ', obj_1.sex)
