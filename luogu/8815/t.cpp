
tree work(token){
    if ( token is number ){
        new_tree = create_tree(number)
        return new_tree;
    }

    if( token is operator ){
        new_tree = create_tree(token)
        new_tree.left = pre_tree
        new_tree.right = work(next token)
    }

}
