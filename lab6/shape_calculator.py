import geometry_utils

d = {"circle_area" : geometry_utils.circle_area, "circle_perimeter":geometry_utils.circle_perimeter,"rectangle_area":geometry_utils.rectangle_area, "triangle_area":geometry_utils.triangle_area, "rectangle_perimeter":geometry_utils.rectangle_perimeter }
print("Available shapes: circle, rectangle, triangle")
print("Available calculations: _area, _perimeter (e.g., circle_area)")
op = input("Enter the operation you want to perform: ")

s=0
if op == "circle_area":
    r = int(input("Enter radius "))
    s = d[op](r)
elif op == "circle_perimeter":
    r = int(input("Enter radius "))
    s = d[op](r)
elif op == "rectangle_area":
    w = int(input("Enter width "))
    h = int(input("Enter height "))
    s =d[op](w, h)
elif op == "rectangle_perimeter":
    w = int(input("Enter width "))
    h = int(input("Enter height "))
    s =d[op](w, h)
elif op == "triangle_area":
    b = int(input("Enter base "))
    h = int(input("Enter height "))
    s = d[op](b, h)
else:
    print("Wrong shape")
    raise ValueError("Wrong shape")

print("Result :")
print(s)