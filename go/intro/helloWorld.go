/*go code intro
vars, if/else, loops, funcs, multi return
*/
package main
import (
	"fmt"
	"errors"
	"math"
)

//declaring vars here (like package) must be done
//var i int= 9

func expo(base float64, power int) float64{
	ans := 1.0
	for i:= 0; i < power; i++{
		ans *= base
	}
	return ans
}

func sqrt(val float64) (float64, error){
	//two return vals
	if (val < 0){ return 0, errors.New("Undefined for negative numbers")}
	return math.Sqrt(val), nil
}

func main(){
/*	var i int= 42
	j := 42
	k := "a string"
//%v for "value", %T for "type"
	fmt.Printf("My int j= %v, k=%v\n", j, k)


//if stmt
	if(j > 40){
		fmt.Println(j)
	}
*/

//func call: expo
	var funcVal float64= expo(3.0, 3)
	fmt.Printf("expo(3.0, 3) returns: %v\n", funcVal)

//func call sqrt
	sqrtVal, err:= sqrt(-169.0)
	if err != nil{
		fmt.Println(err)
	} else { 
		fmt.Println(sqrtVal)
	}

	//arrays
	/*arrays are fixed sized */
	var arr [4]int
	arr[0]= 1
//	arr2 := [3]int{1, 2, 3}
//	fmt.Printf("arr is: %v\n", arr)
//	fmt.Printf("arr2 is: %v\n", arr2)

	//slices
	//like array but no size specified
	slice := []int{4,3,2,1,0}
	fmt.Printf("First slice is: %v\n", slice)
	slice= append(slice, -1)
	fmt.Printf("append returns new slice: %v\n", slice)

	//maps
	//like dicts
	//map[key T]value T
	vertices:= make(map[string]int)
	vertices["triangle"]= 3
	vertices["rect"]= 4
	vertices["pentagon"]= 5
	fmt.Printf("map is: %v\n", vertices)
	//delete from map
	//delete(mapName, key)
	delete(vertices, "rect")
	fmt.Printf("map deleted entry: %v\n", vertices)


	//loops
	//for loop
	for i:= 0; i<4; i++ {
		fmt.Println(i)
	}
	//while loop
	var l int= 0
	for(l < 2){
		println("while loop works")
		l++
	}
	//iterate over array/slice/map
	//map would give key, value
	for index, value := range slice{
		fmt.Println("index: ", index, "value: ", value)
	}
}