use super::conteiner::Conteiner;


pub struct Basket<T>{
    item: Option<T>,
}

impl<T> Basket<T>{
    pub fn new (item: T) -> Self{
        Basket{item: Some(item)}
    }
}

impl<T> Conteiner<T> for Basket<T>{
    fn get(&mut self) -> Option<T>{
        self.item.take()
    }

   fn put(&mut self, item: T)
    {
        self.item = Some(item);
    }

    fn is_empty(&self) -> T{
        self.item.is_none()
    }
}