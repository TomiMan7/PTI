import datetime

def zero():
	return "Vasarnap"

def one():
	return "Hetfo"

def two():
	return "Kedd"

def three():
	return "Szerda"

def four():
	return "Csutortok"

def five():
	return "Pentek"

def six():
	return "Szombat"

def number_to_day(argument):
	switcher = {
	0:zero,
	1:one,
	2:two,
	3:three,
	4:four,
	5:five,
	6:six,
	}
	
	func = switcher.get(argument, lambda: "Invalid month")
	print func()

def addyear(y,d):
	dd = d
	year = y
	while year<3000:
		year = year + 1
		if (((year % 4 ) == 0) and (((year % 100) != 0) or ((year % 400) == 0))):
			dd = (dd + 2 ) % 7
		else:
			dd = (dd + 1 ) % 7
		return dd

year = input("Ev:")
month = input("Honap:")
day = input("Nap:")
mydate = datetime.date(year,month,day)
wd = addyear(year, int(mydate.strftime("%w")))
print 'Szulinapom erre a napra esik 3000ben:'
number_to_day(wd)
