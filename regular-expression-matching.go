package main

import "fmt"
import "strings"


func isMatch(s string, p string) bool {
	pair := combo {&s, &p}
    return pair.match()
}


type combo struct {
	text, pattern *string
}

type pattern interface {
	match() bool
}


func (pair combo) match() bool{

	/* Tells us if the pattern matched the text */
	yep := false
	got_it := false
	/* Pattern idx and text idx */
	p_idx := 0; t_idx := 0

	p_max := len(*pair.pattern)
	t_max := len(*pair.text)


	for (p_idx != p_max && t_idx != t_max) {
		
		if (strings.Compare(string((*pair.pattern)[p_idx]), "*") == 0) {
			yep = false
			p_idx += 1
			for (t_idx != t_max && p_idx <= p_max) {
				/* If reach the end of pattern string; 
				 * else if char after * matches after 0 or more chars in the text; 
				 * else */
				if (p_idx == p_max) {
					got_it = true 
					break 
				} else if ((*pair.text)[t_idx] == (*pair.pattern)[p_idx]) {
					p_idx += 1; t_idx += 1
					yep = true
					break
				} else {
					t_idx += 1
				}
			} /* If the char literal in test matches char literal in the pattern */
            if !yep { break }

		} else if (strings.Compare(string((*pair.pattern)[p_idx]), ".") == 0) {
			p_idx += 1; t_idx += 1
		} else {
			/* Break if reach end of text
			 *  */
			if (t_idx == t_max) {
				break
			} else if ((*pair.pattern)[p_idx] != (*pair.text)[t_idx]) {
				break
			} else {
				p_idx += 1; t_idx += 1
			}
		}
	}

	return ((p_idx == p_max && t_idx == t_max) || got_it)
}



func main() {

	fmt.Printf("The pattern matches?: %v\n", isMatch("abcdefgadsigbk", "abcdefgadsigbk"))
	fmt.Printf("The pattern matches?: %v\n", isMatch("abcdefghijk", "ab.*defg*k"))
	fmt.Printf("The pattern matches?: %v\n", isMatch("abcdefgadsigbkj", "a*k"))
	fmt.Printf("The pattern matches?: %v\n", isMatch("abcdefgadsigbkj", "a*k."))

}