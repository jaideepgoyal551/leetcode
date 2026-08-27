/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        let n = functions.length ;
        for(let idx = n - 1 ; idx >= 0 ; idx--) {
            x = functions[idx](x) ;
        }
        return x ;
        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */