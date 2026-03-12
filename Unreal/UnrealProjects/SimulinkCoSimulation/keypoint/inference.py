# Use this file to inference on a openCV capture
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import torch
import sys
import argparse
from ultralytics import YOLO

MODEL_PATH = './best.pt' 
MODEL = None

def predict(frame: np.ndarray, model_path: str = None) -> np.ndarray:
    """
    Process the input frame from openCV through the model and 
    Return the normalizedkeypoints.
    
    :param model: PyTorch model for inference
    :param frame: Input frame from openCV capture (H x W x C) in BGR format
    :return: Normalized keypoints as a numpy array of shape (num_keypoints, 2)
    """
    global MODEL
    
    if MODEL is None:
        MODEL = YOLO(MODEL_PATH, task='pose')
    model = MODEL

    results = model.predict(frame, verbose=False)
    if len(results) > 0 and len(results[0].keypoints.xyn) > 0:
        pred_keypoints = results[0].keypoints.xyn[0].cpu().numpy()
    else:
        pred_keypoints = np.array([])

    return pred_keypoints
