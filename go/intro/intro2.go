/*
go intro 2:
structs, pointers, struct methods
*/
package main
import(
	"fmt"
)

type bankAcc struct{
	//name and type
	name string
	accNum int
	balance float64
}

type rect struct{
	width, height int
}
//Method on rect struct
//func (<var name> <struct>) <method name> <return type>{}
func (r rect) area() int{
	return r.width * r.height
}

func (r *rect) perim() int{
	return 2*r.width + 2*r.height
}

func main(){
	//struct
	account:= bankAcc{name: "Eric", accNum: 1, balance: 1000.0}
	fmt.Println(account)
	fmt.Println(account.accNum)

	//calling struct method
	r := rect{width: 7, height: 5}
	fmt.Println("area: ", r.area())
	//calling perim method w/ pointer
	var rectPtr *rect= &r
	fmt.Println("perim: ", rectPtr.perim())

	//pointers
	var temp int= 0
	var ptr *int= &temp
	incr(ptr)
	fmt.Printf("Incremented w/ ptr: %v\n", temp)
}

func incr(x *int){
	//increments var passed in. Needs ptr
	*x++
}