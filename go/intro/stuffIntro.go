package main
import(
	"fmt"
)

func main(){
	var a int= 10//1010
	var b int= 3 //0011
	fmt.Println(a &^ b)//8= 1000
	// a &^ b: clear b's bits from a
}