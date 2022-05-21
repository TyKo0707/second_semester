from material_point import MaterialPointX, MaterialPointXY

k = int(input("Input k: "))
n = int(input("Input n: "))
t = float(input("Input t: "))

coords = []
distances = []
xs = []
xys = []

for i in range(k):
    cl = MaterialPointX(t)
    xs.append(cl)
    print(cl)
    for j in range(i):
        dist = cl.get_distance(xs[j].get_x(), xs[j].get_y())
        coordinates = [cl.get_x(), cl.get_y(), xs[j].get_x(), xs[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

for i in range(n):
    cl = MaterialPointXY(t)
    xys.append(cl)
    print(cl)
    for j in range(i):
        dist = cl.get_distance(xys[j].get_x(), xys[j].get_y())
        coordinates = [cl.get_x(), cl.get_y(), xys[j].get_x(), xys[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

for i in range(k):
    for j in range(n):
        dist = xs[i].get_distance(xys[j].get_x(), xys[j].get_y())
        coordinates = [xs[i].get_x(), xs[i].get_y(), xys[j].get_x(), xys[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

ind = distances.index(max(distances))
print(f'Max distance: {distances[ind]}')
print(f'Between points with coordinates: ({coords[ind][0]}; {coords[ind][1]}), ({coords[ind][2]}; {coords[ind][3]})')
