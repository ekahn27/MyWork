/*
SOLVED

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that
the 6th prime is 13.

What is the 10,001 st prime number?
*/
package main
import(
	"fmt"
	"math"
)

func isPrime(num float64) bool{
	max := int(math.Floor(math.Sqrt(num)))
	numInt:= int(num)
	for i:= 2; i <= max; i++ {
		if numInt % i == 0{
			return false
		}
	}
	return true
}

func solve7() int{
	var primeIndex int= 6
	var currPrime int= 13
	for currVal:= 15; primeIndex != 10001; currVal += 2 {
		if isPrime(float64(currVal)) {
			currPrime= currVal
			primeIndex++
		}
	}
	return currPrime
}

func main(){
	var ans int= solve7()
	fmt.Println("Answer to 7:", ans)
}
