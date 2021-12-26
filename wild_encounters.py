import os
import json
import pandas as pd

def species(name):
  return 'SPECIES_' + name.upper()

with open('src/data/wild_encounters.json') as f:
  we = json.load(f)

df = pd.read_csv('wild_encounters.csv')

encounters = we['wild_encounter_groups'][0]['encounters']

for index, row in df.iterrows():
  map = row['Map']
  mapObj = [x for x in encounters if x['base_label'] == ('g' + map)][0]
  if not pd.isnull(row['Grass 20']):
    mons = mapObj['land_mons']['mons']
    mons[0]['species'] = species(row['Grass 20'])
    mons[1]['species'] = species(row['Grass 20.1'])
    mons[2]['species'] = species(row['Grass 10'])
    mons[3]['species'] = species(row['Grass 10.1'])
    mons[4]['species'] = species(row['Grass 10.2'])
    mons[5]['species'] = species(row['Grass 10.3'])
    mons[6]['species'] = species(row['Grass 5'])
    mons[7]['species'] = species(row['Grass 5.1'])
    mons[8]['species'] = mons[10]['species'] = species(row['Grass 5.2'])
    mons[9]['species'] = mons[11]['species'] = species(row['Grass 5.3'])
  if not pd.isnull(row['Water 60']):
    mons = mapObj['water_mons']['mons']
    mons[0]['species'] = species(row['Water 60'])
    mons[1]['species'] = species(row['Water 30'])
    mons[2]['species'] = species(row['Water 5'])
    mons[3]['species'] = mons[4]['species'] = species(row['Water 5.1'])
  if not pd.isnull(row['Fishing 70']):
    mons = mapObj['fishing_mons']['mons']
    mons[0]['species'] = species(row['Fishing 70'])
    mons[1]['species'] = species(row['Fishing 30'])
    mons[2]['species'] = species(row['Fishing 60'])
    mons[3]['species'] = species(row['Fishing 20'])
    mons[4]['species'] = species(row['Fishing 20.1'])
    mons[5]['species'] = species(row['Fishing 40'])
    mons[6]['species'] = species(row['Fishing 40.1'])
    mons[7]['species'] = species(row['Fishing 15'])
    mons[8]['species'] = mons[9]['species'] = species(row['Fishing 5'])
  if not pd.isnull(row['Rock 60']):
    mons = mapObj['rock_smash_mons']['mons']
    mons[0]['species'] = species(row['Rock 60'])
    mons[1]['species'] = species(row['Rock 30'])
    mons[2]['species'] = species(row['Rock 5'])
    mons[3]['species'] = mons[4]['species'] = species(row['Rock 5.1'])

with open('src/data/wild_encounters.json', 'w') as f:
  json.dump(we, f, indent=2)
