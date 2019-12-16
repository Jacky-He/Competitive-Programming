
var goto: [Int] = [0]
for x in 1...100
{
    goto.append (x)
}
goto [54] = 19
goto [90] = 48
goto [99] = 77
goto [9] = 34
goto [40] = 64
goto [67] = 86
var currentSquare: Int = 1

func canGo (steps a: Int) -> Bool
{
    return (currentSquare + a <= 100)
}

var input: Int = Int (readLine (strippingNewline: true)!)!
while (input != 0)
{
    if canGo (steps: input)
    {
        currentSquare += input
        currentSquare = goto [currentSquare]
    }
    print ("You are now on square \(currentSquare)");
    if (currentSquare == 100)
    {
        print ("You Win!");
        break;
    }
    input = Int (readLine (strippingNewline:true)!)!
}
if (input == 0)
{
    print ("You Quit!");
}

