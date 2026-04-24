class Vehicle:
    vid = ""
    model=""
    year = -1

    def __init__(self,vid,model,year):
        self.vid=vid
        self.model = model
        self.year = year
    def __str__(self):
        return f"VID: {self.vid} | Model: {self.model} ({self.year})"
    def __eq__(self, other):
        return self.vid==other.vid
    def is_new(self,n):
        if (2026-int(self.year)<=n):
            return True
        else:
            return False

class Car(Vehicle):
    fuel_type=""
    doors = -1
    def __init__(self,vid,model,year,fuel_type,doors):
        self.fuel_type=fuel_type
        self.doors = doors
        super().__init__(vid,model,year)
    def __str__(self):
        return f"[Car] VID: {self.vid} | Model: {self.model} ({self.year}) | Fuel: {self.fuel_type} | {self.doors} doors"


class Truck(Vehicle):
    max_load = -1
    axles = -1

    def __init__(self, vid, model, year, max_load, axles):
        self.max_load = max_load
        self.axles = axles
        super().__init__(vid, model, year)

    def __str__(self):
        return f"[Truck] VID: {self.vid} | Model: {self.model} ({self.year}) | Load: {self.max_load} | {self.axles} axles"

class Motorcycle(Vehicle):
    engine_cc = -1
    type = ""

    def __init__(self, vid, model, year, engine_cc, type):
        self.engine_cc = engine_cc
        self.type = type
        super().__init__(vid, model, year)

    def __str__(self):
        return f"[Motorcycle] VID: {self.vid} | Model: {self.model} ({self.year}) | Eng: {self.engine_cc} | Type : {self.type}"

def save_fleet_to_file(vehicles, filename):
    with open(filename,'w',encoding='utf-8') as f:
        for v in vehicles:
            if isinstance(v,Car):
                f.write(f"Car,{v.vid},{v.model},{v.year},{v.fuel_type},{v.doors}\n")
            if isinstance(v,Truck):
                f.write(f"Truck,{v.vid},{v.model},{v.year},{v.max_load},{v.axles}\n")
            if isinstance(v,Motorcycle):
                f.write(f"Motorcycle,{v.vid},{v.model},{v.year},{v.engine_cc},{v.type}\n")
def load_fleet_from_file(filename):
    l=[]
    with open(filename,'r') as f:
       for line in f:
           data = line.strip().split(',')
           if data[0]=="Car":
               c = Car(data[1],data[2],data[3],data[4],data[5])
               l.append(c)
           if data[0] == "Truck":
               t = Truck(data[1], data[2], data[3], data[4], data[5])
               l.append(t)
           if data[0] == "Motorcycle":
               m = Motorcycle(data[1], data[2], data[3], data[4], data[5])
               l.append(m)
    return l

Car1 = Car("V001","Tesla Model 3",2023,"Electric",4)
Car2= Car("V002","Toyota Corolla",2018,"Petrol",4)
Truck1= Truck("T101","Volvo FH16",2019,25000,6)
Truck2= Truck("T102","Mercedes Actros",2021,18000,4)
Motorcycle1 = Motorcycle("M302","Harley Davidson",2015,1200,"Cruiser")
Motorcycle2 = Motorcycle("M301","Yamaha R1",2024,998,"Sport")
vehicles=[Car1,Car2,Truck1, Truck2, Motorcycle1,Motorcycle2]
save_fleet_to_file(vehicles,"fleet.txt")

readvehicles=[]
readvehicles = load_fleet_from_file("fleet.txt")

print("--- All Vehicles ---")
for v in readvehicles:
    print(v)

print(" --- Recent Vehicles (Last 4 Years) ---")
for v in readvehicles:
    if(v.is_new(4)):
        print(v)


print("--- Electric Cars Only ---")
for v in readvehicles:
    if(isinstance(v,Car)):
        if v.fuel_type=="Electric":
            print(v)





