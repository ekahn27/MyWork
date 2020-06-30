/*
SOLVED

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 +...+ 10^2=385
The square of the sum of the first ten natural numbers is,

(1+2+...+10)^2=552=3025
Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025−385=2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.)
*/
package main
import(
	"fmt"
)

func solve6() int{
	var sqrOfSums int= 101*50
	sqrOfSums *= sqrOfSums

	var sumOfSqrs int= 0
	var cnt int= 1
	for cnt= 1; cnt <= 100; cnt++{
		sumOfSqrs += cnt * cnt
	}
	return sqrOfSums - sumOfSqrs
}

func main(){
	var ans int= solve6()
	fmt.Println("Answer to 6:", ans)
}
