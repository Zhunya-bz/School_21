package main

import "fmt"
import "bufio"
import "os"
import "strconv"
import "math"
import "sort"
import "flag"

func castToFloat(fl float64) float64 {
	var ret float64
	ret = math.Trunc(fl * 100) / 100
	return (ret)
}

func readInput(numbers []float64) []float64 {
	scanner := bufio.NewScanner(os.Stdin)
    
    for {
        scanner.Scan()
        
        text := scanner.Text()

        if len(text) != 0 {
			f, err := strconv.ParseFloat(text, 8)
			p := castToFloat(f)
			numbers = append(numbers, p)
			if err != nil {
				fmt.Println(err)
				os.Exit(1)
			}
        } else {
            break
        }
    }
	return (numbers)
}

func mean(numbers []float64, flag int) float64 {
	var sum float64
	for i := 0; i < len(numbers); i++ {
		sum += numbers[i]
	}
	if flag == 1 {
		fmt.Printf("Mean: %.2f\n", castToFloat(sum / float64(len(numbers))))
	}
	return (sum / float64(len(numbers)))
}

func median(numbers []float64) {
	sort.Float64s(numbers)
	if len(numbers) % 2 == 1 {
		fmt.Printf("Median: %.2f\n", castToFloat(numbers[len(numbers) / 2]))
	} else {
		fmt.Printf("Median: %.2f\n", castToFloat((numbers[len(numbers) / 2] + numbers[len(numbers) / 2 - 1]) / 2))
	}
}

func mode(numbers []float64) {
	var m = make(map[float64] int)
	m[numbers[0]] = 0
	var flag int

	for i := 0; i < len(numbers); i++ {
		flag = 0
		for key, value := range m { // Порядок не определен 
			if key == numbers[i] {
				m[key] = value + 1
				flag = 1
				break
			}
		}
		if flag == 0 {
			m[numbers[i]] = 1
		}
	}
	var max int
	max = 0
	var goal_num float64
	for key, value := range m { // Порядок не определен 
		if (value > max) {
			max = value
			goal_num = key
		}
		if (value == max) {
			if (key < goal_num) {
				goal_num = key
			}
		}
	}
	fmt.Printf("Mode: %.2f\n", castToFloat(goal_num))
}

func sd(numbers []float64) {
	mu := mean(numbers, 0)
	var sum float64
	sum = 0
	for i := 0; i < len(numbers); i++ {
		sum += math.Pow(numbers[i] - mu, 2)
	}
	sd := math.Sqrt(sum / float64(len(numbers)))
	fmt.Printf("SD: %.2f\n", castToFloat(sd))
}

func main() {
	var bool_mean *bool 
	bool_mean = flag.Bool("Mean", true, "mean value")
	bool_median := flag.Bool("Median", true, "median number in sort array")
	bool_mode := flag.Bool("Mode", true, "mode of frequent occurrence")
	bool_sd := flag.Bool("SD", true, "sd - Standard Deviation")
	flag.Parse()

	var numbers []float64

    numbers = readInput(numbers)
	if (len(numbers) <= 0) {
		fmt.Printf("Error\n")
		os.Exit(1)
	}
    // fmt.Println(numbers)
	if *bool_mean {
		mean(numbers, 1)
	}
	if *bool_median {
		median(numbers)
	}
	if *bool_mode {
		mode(numbers)
	}
	if *bool_sd {
		sd(numbers)
	}
}
