/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    if(arr.length === 0){
        return null
    }
    const stack = [arr]
    while(stack.length>0){
        const current = stack.pop()
        if(Array.isArray(current)){
          for(let i=current.length-1;i>=0;i--){
            stack.push(current[i])
          }
        } 
        else{
          yield current
        }
     }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */