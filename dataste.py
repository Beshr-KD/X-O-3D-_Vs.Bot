import pandas as pd
import numpy as np

# قراءة ملف Excel
df = pd.read_csv('D:\study\project\dataset.csv')

# تغيير ترتيب الصفوف بشكل عشوائي
df = df.sample(frac=1, random_state=42).reset_index(drop=True)

# حفظ التغييرات في ملف Excel جديد
df.to_csv('D:\study\project\dataset2.csv', index=False)
