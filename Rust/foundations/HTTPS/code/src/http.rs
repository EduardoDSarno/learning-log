#[derive(Debug)]
pub struct Http {
    pub method: String,
    pub path: String,
    pub version: f32,
}

impl Http {
    pub fn new(method: String, path: String, version: f32) -> Self {
        Http { method, path, version }
    }
}
