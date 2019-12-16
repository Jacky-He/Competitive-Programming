func gcd (a: Int, b: Int) -> Int
{
    if b == 0
    {
        return a;
    }
    return gcd (a: b, b: a%b);
}
let str: String = String (" ABCDEFGHIJKLMNOPQRSTUVWXYZ.,!?");
for _ in 1...5
{
    var input = readLine ()!.split(separator: " ").map {Int($0)!}
    let numParts = input [0];
    var GCD = input [1];
    for x in 2...numParts
    {
        GCD = gcd (a: GCD, b: input [x]);
    }
    var result: String = String();
    for x in 1...numParts
    {
        let originalString = input [x]/GCD;
        result.append (str [str.index(str.startIndex, offsetBy:(originalString/100)%100)]);
        result.append (str [str.index(str.startIndex, offsetBy: originalString%100)]);
    }
    if (result.last == " ")
    {
        print (result.dropLast())
    }
    else
    {
        print (result);
    }
}




