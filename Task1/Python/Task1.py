# находит все числа из промежутка [minValue, maxValue] которых нет в lst
def getMissingNumbers(minValue, maxValue, lst):
    fullRange = list(map(lambda n: n + 1, range(minValue, maxValue)))
    return list(filter(lambda x: not x in lst, fullRange))


# обработка файла
def handleSequence(file):
    currentList = []
    minValue = 32000
    maxValue = 0
    for line in file:
        line = int(line)
        currentList.append(line)
        if (line > maxValue):
            maxValue = line
        if (line < minValue):
            minValue = line
        print("Последовательность: " + str(currentList))
        print("Для полноты не хватает: " + str(getMissingNumbers(minValue, maxValue, currentList)) + "\n")


# файл с последовательностью чисел
file = open('input.txt')
handleSequence(file)