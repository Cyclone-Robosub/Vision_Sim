% --- 1. Load a test frame ---
original_frame = imread('image.png'); 


% --- 2. Ensure Python can find your script ---
if count(py.sys.path, '') == 0
    insert(py.sys.path, int32(0), '');
end

% (Optional) Reload the module if you've been making changes to the Python file
py.importlib.reload(py.importlib.import_module('inference'));

% --- 3. Send the frame to Python and get it back ---
result = py.inference.predict(original_frame);

double(result)