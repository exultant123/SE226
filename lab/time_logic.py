time = input("Enter time in seconds\n")
time = int(time)
hours = int(time)/3600
minutes = (time - int(hours)*3600)/60
seconds = (time - int(hours)*3600 -int(minutes)*60)
print(str(time)+" seconds is "+str(int(hours)) +" hours, " + str(int(minutes)) +" minutes and " + str(int(seconds)) +" seconds\n")

