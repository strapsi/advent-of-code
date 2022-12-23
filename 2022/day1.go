package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fileBytes, fileReadError := os.ReadFile("./inputs/day1")
	if fileReadError != nil {
		panic("could not read file")
	}
	lines := strings.Split(string(fileBytes), "\n")
	mostCalories := 0
	currentCalories := 0

	for _, line := range lines {
		if len(line) == 0 {
			if currentCalories > mostCalories {
				mostCalories = currentCalories
			}
			currentCalories = 0
		} else {
			calories, convError := strconv.Atoi(line)
			if convError != nil {
				panic("line was not a number")
			}
			currentCalories += calories
		}
	}

	fmt.Println(mostCalories)
}
