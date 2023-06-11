use actix_web::{App, HttpServer, get, Responder, HttpResponse, web, HttpRequest, http::StatusCode};
use actix_files::{NamedFile, Files};

use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct Params {
    secret_phrase: Option<String>
}

#[get("/check")]
async fn check(query_data: web::Query<Params>, req: HttpRequest) -> impl Responder {
    let flag = std::env::var("FLAG").unwrap_or("test_flag".to_string());
    let query = query_data.into_inner();
    match query.secret_phrase {
        Some(phrase) => match phrase.as_str() {
            "radical" => HttpResponse::Ok().status(StatusCode::TEMPORARY_REDIRECT).append_header(("Location", format!("/members_only.html?flag={}", flag))).finish(),
            _ => NamedFile::open("./static/not_member.html").unwrap().into_response(&req)
        },
        None => NamedFile::open("./static/not_member.html").unwrap().into_response(&req)

        
    }
}


#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let address = "0.0.0.0";
    let port: u16 = std::env::var("PORT").unwrap_or("8080".to_string()).parse().unwrap();

    println!("Running at http://{address}:{port}");

    HttpServer::new(|| {
        App::new()
            .service(check)
            .service(
                //serve files in "static/" directory at the root("/")
                Files::new("/", "./static/").index_file("index.html")
            )
    })
    .bind((address, port))?
    .run()
    .await
}
