import pandas as pd
import numpy as np

# قراءة ملف Excel
df = pd.read_csv('D:\study\project\dataset.csv')

# تغيير ترتيب الصفوف بشكل عشوائي
df = df.sample(frac=1, random_state=42).reset_index(drop=True)

