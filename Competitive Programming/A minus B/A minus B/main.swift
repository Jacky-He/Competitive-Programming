var n: Int = Int (readLine(strippingNewline: true)!)!
for _ in 0..<n
{
    var stringarr = readLine (strippingNewline: true)!.split{$0 == " "}
    print (Int(stringarr [0])! - Int(stringarr [1])!)
}
