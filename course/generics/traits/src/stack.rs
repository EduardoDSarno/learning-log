use super::conteiner::Conteiner;


pub struct Stack<T>{
    items:Vec<T>,
}
impl<T> Stack<T>{
    pub fn new(items:Vec<String>) -> Self{
        Stack{items}
    }
}

impl<T> Conteiner<T> for Stack<T>{

    fn get(&mut self) ->Option<T>{
        self.items.pop()
    }

    fn put(&mut self, item: T){
        self.items.push(item)
    }

    fn is_empty(&self)->T{
        self.item.is_none()
    }
}


