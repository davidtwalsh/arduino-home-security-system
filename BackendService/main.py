from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()


@app.post("/motion")
def motion_detected():
    print("motion detected")
    return {"status": "motion received"}


