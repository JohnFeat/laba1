MAX_INPUT_SIZE = 256
MAX_HOUSE_NUM = 256
MAX_PRICE_PER_MONTH = 20_000

class Service:
    def __init__(self):
        self.country = None
        self.city = None
        self.region = None
        self.street = None

        self.houseNum = None
        self.countResidents = None
        self.paidResidents = None

        self.pricePerMonth = 0

        self.registerHouse()
    
    def registerHouse(self):
        """
            Регистрация нового дома в системе
        """
        while not self.country:
            try:
                self.country = input("Введите страну: ")
                if len(self.country) > MAX_INPUT_SIZE:
                    print(f"Превышно максимальное количество символов! ({MAX_INPUT_SIZE})")
                    self.country = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.region:
            try:
                self.region = input("Введите регион: ")
                if len(self.region) > MAX_INPUT_SIZE:
                    print(f"Превышно максимальное количество символов! ({MAX_INPUT_SIZE})")
                    self.region = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.city:
            try:
                self.city = input("Введите город: ")
                if len(self.city) > MAX_INPUT_SIZE:
                    print(f"Превышно максимальное количество символов! ({MAX_INPUT_SIZE})")
                    self.city = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.street:
            try:
                self.street = input("Введите улицу: ")
                if len(self.street) > MAX_INPUT_SIZE:
                    print(f"Превышно максимальное количество символов! ({MAX_INPUT_SIZE})")
                    self.street = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.houseNum:
            try:
                self.houseNum = int(input("Введите номер дома: "))
                if self.houseNum > MAX_HOUSE_NUM:
                    print(f"Превышно максимальное число! ({MAX_HOUSE_NUM})")
                    self.houseNum = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.countResidents:
            try:
                self.countResidents = int(input("Введите число жителей дома: "))
                if self.countResidents > 1e+6:
                    print(f"Превышно максимальное число! ({1e+6})")
                    self.countResidents = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        while not self.pricePerMonth:
            try:
                self.pricePerMonth = float(input("Введите плату за услуги ЖЭС в месяц: "))
                if self.pricePerMonth > MAX_PRICE_PER_MONTH:
                    print(f"Превышно максимальное число! ({MAX_PRICE_PER_MONTH})")
                    self.pricePerMonth = None
            except:
                print("Произошла ошибка при вводе данных!")
        
        print(f"Зарегестрирован дом по адресу: страна {self.city}, рег. {self.region}, г. {self.city}, ул. {self.street}, д. {self.houseNum}")
        print(f"Число жильцов: {self.countResidents}")
        print(f"Установленная плата: {self.pricePerMonth} р/мес.")
        print(f"Общая сумма платы ЖЭС: {self.totalCost()} р/мес.")

    def totalCost(self) -> float:
        """
            Подсчёт общей суммы платы за услуги ЖЭС
        """
        return self.countResidents * self.pricePerMonth
    
    def currentCost(self) -> float:
        """
            Подсчет текущей платы за услуги ЖЭС
        """
        return self.totalCost() - (self.paidResidents * self.pricePerMonth)
    
    def editResident(self, act) -> None:
        if act == 1:
            self.paidResidents += 1
            return
        
        if act == 0:
            self.paidResidents -= 1
            return
        
        self.paidResidents += 1
        

a = Service()