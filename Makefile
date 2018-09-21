all: regular_expression

run: run_regular_expression

clean: clean_regular_expression


regular_expression:
	go build regular-expression-matching.go

run_regular_expression:
	./regular-expression-matching

clean_regular_expression:
	go clean
